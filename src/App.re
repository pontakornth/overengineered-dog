type dogResponse = {messages: array(string), status: string};
module Decode {
  let dogResponse = (data: Js.Json.t) =>
      Json.Decode.{messages: field("messages", array(string), data), status: field("status", string, data)};
};

type action = 
   | SetDogsData(array(string))
   | SetSearchTerm(string);
type state = {searchTerm: string, dogsData: array(string)};
[@react.component]
let make = () => {
    let (state, dispatch) = 
        React.useReducer(
          (state, action) =>
             switch (action) {
               | SetDogsData(dogsData) => {...state, dogsData: dogsData}
               | SetSearchTerm(searchTerm) => {...state, searchTerm: searchTerm}
             },{searchTerm: "", dogsData: [||]},
        );
    React.useEffect0(() => {
      Js.Promise.(
        Fetch.fetch("https://dog.ceo/api/breeds/image/random/15")
         |> Js.Promise.then_(Fetch.Response.json)
         |> Js.Promise.then_(json => {
             let dogsData = Decode.dogResponse(json);
             dispatch(SetDogsData(dogsData.messages));
             resolve(dogsData);
            })
         |> ignore
      );
      None;
    }
    );
    <ReasonReactErrorBoundary fallback={_ => "Something went wrong"->React.string}>
      <div> 
        <h1>{React.string("This is a counter")} </h1>
        <input value={state.searchTerm} onChange={event => {
          let value = ReactEvent.Form.target(event)##value;
          dispatch(SetSearchTerm(value))
        } } />
      </div>
    </ReasonReactErrorBoundary>;
}
