public class BookIdBasedSearcher implements BookSearcher {

    private final int id;

    public BookIdBasedSearcher(int id) {
        this.id = id;
    }

    @Override
    public List<BookCopy> search() {
        return null;
    }
}