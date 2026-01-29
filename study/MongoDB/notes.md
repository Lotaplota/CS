`db.books.find({author: "Frank Herbert", rating: 8})` finds all the books by Frank Herbert with 8 as a rating in the books collection
`bookstore> db.books.find({ author: "Terry Pratchett" }, {author: 1, title: 1})` shows only the title and author of the books
`db.books.find({author: "Brandon Sanderson"}).count()` counts how many Brandon Sanderson books are in the collection
`db.books.find().limit(3)` returns the first 3 books
`db.books.find().sort({author: 1})` sorts the books by author in ascending order
- changing the `1` to a `-1` sorts in descending order
`db.books.find({rating: {$gt: 7}})` returns the books which rating is greater than 7
`db.books.find({$or: [{rating: {$gt: 8}}, {pages: 250}]})` returns the books that have ratings greater than 8 or exactly 250 pages

---

### Operators
syntax          | operator                                 |
---------------:|------------------------------------------|
`$gt` or `$gte` | greater than / greater or equal          |
`$lt` or `$lte` | less than / lesser or equal              |
`$or`           | or this is not that different            |


---

it
: iterates over the previous results

---

- most of the parameters are JSON objects, requiring the `{ }` and basic JSON structure