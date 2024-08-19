package zoo.visitor;

import java.util.List;
import zoo.tours.api.Tour;
import zoo.tours.reservations.TourFinder;

// a consumer/client module is one which obtains and uses a service

public class Tourist {

    public static void main(String[] args) {
        Tour tour = TourFinder.findSingleTour();
        System.out.println("Single tour: " + tour);

        List<Tour> tours = TourFinder.findAllTours();
        System.out.println("# tours: " + tours.size());
    }
}
