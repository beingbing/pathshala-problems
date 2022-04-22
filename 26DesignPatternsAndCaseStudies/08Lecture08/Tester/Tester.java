// data access layer

public class Tester {

    private final Library library = new Library(new DBAccessor());

    // validate the parameters first then go ahead with business logic

    public List<BookCopy> SearchBookByBookName(string bookName) {
        if (bookName == null) throw IllegalArgument("book name can not be null");
        BookSearcher bookSearch = new BookNameBasedSearcher(bookName);
        return bookSearch.search();
    }

    public List<BookCopy> SearchBookByAuthorName(string authorName) {
        if (authorName == null) throw new IllegalArgumentException("author name can not be null");
        BookSearcher bookSearch = new AuthorNameBasedSearcher(authorName);
        return bookSearch.search();
    }

    public List<Member> SearchMemberByName(string name, string adminToken) {
        // check validity of arguments
        if (name == null) throw new IllegalArgumentException("member name can not be null");

        // authentication of admin
        if (!UserAuthenticator.isAdmin(adminToken)) throw new IllegalAccessException("only admin can check member data");

        // execute searching
        MemberSearcher memberSearcher = new MemberNameBasedSearcher(name);
        return memberSearcher.search();
    }

    public void addBook(string bookName, Date publicationDate, List<string> authors, string adminToken) {
        if (!UserAuthenticator.isAdmin(adminToken)) throw new IllegalAccessException("only admin can check member data");

        // validation logic

        BookCopy bookCopy = new BookCopy(new BookDetails(bookName, publicationDate, authors), IDGenerator.getUniqueId());

        library.addBookCopy(bookCopy);
    }

    public void deleteBook(int bookCopyId, string adminToken) {
        // illegal arguments validation

        // book search logic
        BookSearcher bookSearch = new BookIdBasedSearcher(bookCopyId);
        List<BookCopy> bookCopies = bookSearch.search();
        if (bookCopies.empty() || bookCopies.size() > 1) throw new RuntimeException("wrong result");

        library.deleteBookCopy(bookCopies[0]);
    }

    public void blockMember(int memberId, string adminToken) {
        // validate function parameters

        // authentication of admin
        if (!UserAuthenticator.isAdmin(adminToken)) throw new IllegalAccessException("only admin can check member data");

        MemberSearcher memberSearcher = new MemberIdBasedSearcher(memberId);

        List<Member> members =  memberSearcher.search();
        if (members.empty() || members.size() > 1) throw new RuntimeException("wrong result");
        library.blockMember(members[0]);
    }

    public void addMember(string name, string phoneNumber, string email) {
        
    }
    
    public void bookIssue(int bookId, int memberId, string adminToken) {
        // validate function parameters

        // authentication of admin
        if (!UserAuthenticator.isAdmin(adminToken)) throw new IllegalAccessException("only admin can check member data");

        BookSearcher bookSearcher = new BookIdBasedSearcher(bookId);
        List<BookCopy> bookCopies = bookSearcher.search();
        if (bookCopies.empty() || bookCopies.size() > 1) throw new RuntimeException("wrong result");

        MemberSearcher memberSearcher = new MemberIdBasedSearcher(memberId);
        List<Member> members = memberSearcher.search();
        if (members.empty() || members.size() > 1) throw new RuntimeException("wrong result");

        library.issueBook(bookCopies[0], members[0]);
    }

    public void submitBook(int bookId, int memberId, string adminToken);

    public List<Member> getBorrowerDetails(string bookName, string adminToken);

    public List<BookCopy> getBooksBorrowedByMember(int memberId, string adminToken);
}
