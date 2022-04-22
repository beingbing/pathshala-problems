public class AuthorNameBasedSearcher implements BookSearcher {

    private final string authorName;

    AuthorNameBasedSearcher(string authorName) {
        this.authorName = authorName;
    }

    @Override
    public List<BookCopy> Search() {
        return null;
    }
}
