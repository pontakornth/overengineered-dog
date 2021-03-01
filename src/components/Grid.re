open ReactFela;
[@react.component]
let make = (~children) => {
    let css = useFela1();
    <div className={
        css(
            Fela.style({
                "display": "grid",
                "grid-template-columns": "repeat(3, 1fr)",
                "grid-template-rows": "masonry",
                "gap": "10px",
                "margin": "auto",
                "width": "80%",
                "max-width": "1280px"
            })
        )
    }>
    {children}
    </div>;
};