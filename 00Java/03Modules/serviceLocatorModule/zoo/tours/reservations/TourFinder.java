package zoo.tours.reservations;

import java.util.ServiceLoader;
import java.util.ArrayList;
import java.util.List;
import zoo.tours.api.Tour;

// This is a 'service locator'. It can find any class that implement a service
// provider interface. A ServiceLoader call is expensive, cache if using in
// real application.


public class TourFinder {

    public static Tour findSingleTour() {
        ServiceLoader<Tour> loader = ServiceLoader.load(Tour.class);
        for (Tour tour : loader) {
            return tour;
        }
        return null;
    }

    public static List<Tour> findAllTours() {
        List<Tour> tours = new ArrayList<>();
        ServiceLoader<Tour> loader = ServiceLoader.load(Tour.class);
        for (Tour tour : loader) {
            tours.add(tour);
        }
        return tours;
    }
}
