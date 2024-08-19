package zoo.tours.api;

// 'service provider interface', as it specifies what behavior our
// service will have.

public interface Tour {

    String name(); // implicitly public
    int length();
    Souvenir getSouvenir();

}
