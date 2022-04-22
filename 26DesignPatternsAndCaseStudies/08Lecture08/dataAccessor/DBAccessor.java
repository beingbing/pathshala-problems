public class DBAccessor {

    public Results getBookByName(string bookName);

    public Results getBookByAuthorName(string name);

    public Results getMembersByName(string name);

    public void insertBookCopy(BookCopy bookCopy);

    public void deleteBookCopy(BookCopy bookCopy);

    public void markAsBlocked(Member member);

    public void issueBookCopyToMember(BookCopy bookCopy, Member member);

    public void submitBookCopyFromMember(BookCopy bookCopy, Member member);

    public boolean isCopyAvailable(BookCopy bookCopy);

    public Results getBorrower(BookCopy bookCopy);

    public Results getBorrowedBooks(Member member);
}