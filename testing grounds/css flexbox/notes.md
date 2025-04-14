## parent attributes
- flex-direction: *row*, column, column-reverse
    - is set to row by default
- justify-content: *flex-start*, flex-end, center, space-between, space-around, space-evenly
    - align items in the MAIN AXIS
- align-items: *flex-start*, flex-end, center, baseline
    - aligns items in the CROSS AXIS
- flex-wrap: *nowrap*, wrap
    - setting to wrap enables the align-content property
- align-content: flex-start, flex-end, center, baseline, *stretch*
    - is enabled by flex-wrap being set to wrap
- gap:
    - adds a gap between elements

## child attributes
- flex-grow:
    - when the item has to grow, it'll try to as much as it can and the number represents how fast it will try to do so
- flex-shrink:
    - when the item has to shrink, it'll try to as much as it can and the number represents how fast it will try to do so
- flex basis:
    - this forces the item to assume a defined width
    - `flex-basis: 0;` will try to shrink it to the max
- flex:
    - shorthand for the flex-grow, flex-shrink, and flex-basis
    - can be called by `flex: 0 0 20%;` as a consequence of the above
    - once I used the `flex: 0 0 calc(25% -6px);` to add a gap between items
        - 😎 *great catch over ChatGPT btw...*
- align-self:
    - overrides the parent's display
- order: *0*
    - TODO
    - use carefully because it messes with the semantics

## other
- border-sizing: border-box
    - this one makes the border be part of the size calculations of the item
    - makes the border grow "inward"
