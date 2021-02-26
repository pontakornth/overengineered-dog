[@react.component]
let make = () =>
    <ReasonReactErrorBoundary fallback={_ => "Something went wrong"->React.string}>
      <div> 
        <h1>{React.string("This is a counter")} </h1>
        <Counter/> 
      </div>
    </ReasonReactErrorBoundary>;
