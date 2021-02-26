[@react.component]
let make = () => {
    let (count, setCount) = React.useState(_ => 0);

    <button onClick={_ => setCount(prevCount => prevCount + 1)}>
    {React.int(count)}
    </button>;
}