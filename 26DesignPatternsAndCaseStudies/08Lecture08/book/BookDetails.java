public class BookDetails {

    private final string bookName;
    private final date publicationDate;
    private final List<string> authors;

    BookDetails(string bookName, date publicationDate, List<string> authors) {
        this.bookName = bookName;
        this.publicationDate = publicationDate;
        this.authors = authors;
    }
}
