// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as ReactFela from "reason-fela/src/ReactFela.bs.js";

function Grid(Props) {
  var children = Props.children;
  var css = ReactFela.useFela1(undefined);
  return React.createElement("div", {
              className: Curry._1(css, {
                    display: "grid",
                    "grid-template-columns": "repeat(3, 1fr)",
                    "grid-template-rows": "masonry",
                    gap: "10px",
                    margin: "auto",
                    width: "80%",
                    "max-width": "1280px"
                  })
            }, children);
}

var make = Grid;

export {
  make ,
  
}
/* react Not a pure module */
