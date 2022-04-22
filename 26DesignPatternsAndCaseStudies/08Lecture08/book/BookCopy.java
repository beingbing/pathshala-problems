/*

this class needs all the details of BookDetails class, but to make it inherit that class will be a bad design because
inheritance is done to inherit behavior (functions) not the implementation. And BookDetails is a data class it do not
have any behavior.

Instead of Inheritance we will go for composition.

*/

public class BookCopy {
    
    private final BookDetails bookDetails;
    private final int id;

    public BookCopy(BookDetails bookDetails, int id) {
        this.bookDetails = bookDetails;
        this.id = id;
    }

    
}