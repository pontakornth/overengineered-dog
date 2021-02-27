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
    <ReasonReactErrorBoundary fallback={_ => "Something went wrong"->React.string}>
      <div> 
        <h1>{React.string("This is a counter")} </h1>
        <input value={state.searchTerm} onChange={event => {
          let value = ReactEvent.Form.target(event)##value;
          dispatch(SetSearchTerm(value))
        } } />
        <Counter/> 
      </div>
    </ReasonReactErrorBoundary>;
}
