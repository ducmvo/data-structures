Member
    account PK int

Book
    isbn PK int

Rating
    memberID FK int
    bookID FK int
    rating

MemberList
    Member[] memberList

BookList
    Book[] bookList

RatingList
    Rating[] ratingList



