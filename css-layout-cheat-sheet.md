
# 🧭 CSS Layout Cheat Sheet

## ✅ 1. Center an item horizontally

| Goal | Parent | Child |
|------|--------|-------|
| Center text | `text-align: center` | (no change needed) |
| Center block item (like a `div`) | `display: flex; justify-content: center;` | (no change needed) |
| Center block item (classic way) | — | `margin: 0 auto;` |

## ✅ 2. Center an item vertically

| Context | Parent | Child |
|---------|--------|-------|
| Single line of text | `line-height: [same as height]` | (no change needed) |
| Flex container | `display: flex; align-items: center;` | (no change needed) |
| Absolute positioning | `position: relative;` | `position: absolute; top: 50%; transform: translateY(-50%);` |

## ✅ 3. Align item to the bottom

| Parent | Child |
|--------|-------|
| `display: flex; align-items: flex-end;` | (no change needed) |
| `position: relative;` | `position: absolute; bottom: 0;` |

## ✅ 4. Make items stack vertically

| Parent | Child |
|--------|-------|
| `display: flex; flex-direction: column;` | (items stack vertically) |
| Default `div` behavior | (no change needed — block elements stack by default) |

## ✅ 5. Prevent an item from wrapping

| Parent | Child |
|--------|-------|
| `display: flex; flex-wrap: nowrap;` | (no change needed) |
| — | `white-space: nowrap;` |

## ✅ 6. Allow scrolling inside a box

| Parent (the scrollable box) | Child |
|-----------------------------|-------|
| `max-height: [value]; overflow-y: auto;` | (content can overflow and scroll) |
| `width: [value]; overflow-x: auto;` | (horizontal scrolling) |

## ✅ 7. Limit child width based on parent

| Scenario | CSS |
|----------|-----|
| Child maxes out at 600px, unless parent is smaller | `max-width: 100%; width: 600px;` on child |
| Child width should always match parent | `width: 100%;` |

## ✅ 8. Equal height columns

| Parent | Notes |
|--------|-------|
| `display: flex;` | Flex items naturally get equal height (if they’re in the same row) |

## ✅ 9. Create a responsive grid

| Parent | Child |
|--------|-------|
| `display: grid; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));` | (No changes needed — children fit automatically) |

## ✅ 10. Fix an element to the edge of the screen

| Parent | Child |
|--------|-------|
| — | `position: fixed; top: 0; left: 0; width: 100%;` (for a sticky top bar) |

---

## 🧰 Extra Tips

- Always **check the parent’s `display`** if child positioning isn’t working.
- Use **browser dev tools (F12)** to inspect layout and test live changes.
- Bootstrap makes many of these easier with utility classes like:
  - `d-flex`, `justify-content-*`, `align-items-*`, `w-100`, `m-auto`, etc.
