open ReactFela;
[@react.component]
let make = (~imageUrl) => {
  let css = useFela1();
  <img className={css(Fela.style({
    "display": "block",
    "width": "100%"
  }))} src={imageUrl}></img>;
}