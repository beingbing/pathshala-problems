// this is business layer

public class Library {

    private final DBAccessor dbAccessor;

    public Library(DBAccessor dbAccessor) {
        this.dbAccessor = dbAccessor;
    }

    public void addBookCopy(BookCopy bookCopy) {
        // check validity of parameters

        dbAccessor.insertBookCopy(bookCopy);
    }

    public void deleteBookCopy(BookCopy bookCopy) {
        // check validity of parameters

        // check if bookCopy is available
        // perform deletion
        if (dbAccessor.isCopyAvailable(bookCopy)) dbAccessor.deleteBook(bookCopy);
    }

    public void blockMember(Member member) {
        //
    }

    public void issueBook(BookCopy bookCopy, int memberId) {
        //
    }

    public void submitBook(BookCopy bookCopy, int memberId) {
        //
    }

    public Member getBorrower(BookCopy bookCopy) {
        //
        Results results = dbAccessor.getBorrower(bookCopy);
        return ResultConverter.convertToMember(results);
    }

    public List<BookCopy> getBorrowedBooks(Member member, )

}