// open module zoo.animal.talks { // all exports are opened for reflection, then can't use `opens` inside anymore
module zoo.animal.talks {
   // exports zoo.animal.talks.content to zoo.staff;
    exports zoo.animal.talks.content;
    exports zoo.animal.talks.media;
    exports zoo.animal.talks.schedule;

    opens zoo.animal.talks.content to zoo.staff; // only staff can use reflection
    opens zoo.animal.talks.schedule; // any requiring package can use reflection

    // requires zoo.animal.feeding;
    // requires zoo.animal.care;
    requires transitive zoo.animal.care;
}
