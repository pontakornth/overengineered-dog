// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Counter$FunctionalVite from "./components/Counter.bs.js";
import * as ReasonReactErrorBoundary from "reason-react/src/ReasonReactErrorBoundary.bs.js";

function App(Props) {
  var match = React.useReducer((function (state, action) {
          if (action.TAG === /* SetDogsData */0) {
            return {
                    searchTerm: state.searchTerm,
                    dogsData: action._0
                  };
          } else {
            return {
                    searchTerm: action._0,
                    dogsData: state.dogsData
                  };
          }
        }), {
        searchTerm: "",
        dogsData: []
      });
  var dispatch = match[1];
  return React.createElement(ReasonReactErrorBoundary.make, {
              children: React.createElement("div", undefined, React.createElement("h1", undefined, "This is a counter"), React.createElement("input", {
                        value: match[0].searchTerm,
                        onChange: (function ($$event) {
                            var value = $$event.target.value;
                            return Curry._1(dispatch, {
                                        TAG: /* SetSearchTerm */1,
                                        _0: value
                                      });
                          })
                      }), React.createElement(Counter$FunctionalVite.make, {})),
              fallback: (function (param) {
                  return "Something went wrong";
                })
            });
}

var make = App;

export {
  make ,
  
}
/* react Not a pure module */