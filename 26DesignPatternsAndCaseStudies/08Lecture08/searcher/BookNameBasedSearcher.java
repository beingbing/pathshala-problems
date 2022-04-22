public class BookNameBasedSearcher implements BookSearcher {

    private final string bookName;
    private final DBAccessor dbAccessor;

    public BookNameBasedSearcher(string bookName) {
        this.bookName = bookName;
        this.dbAccessor = new DBAccessor();
    }

    @Override
    public List<BookCopy> Search() {
        Results results = dbAccessor.getBookByName(bookName);
        return ResultConverter().ConvertToBookCopies(results);
    }
}