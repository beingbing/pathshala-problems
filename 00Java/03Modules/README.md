# Creating and Running a Modular Program
## Creating the Files
See the feeding folder for module zoo.animal.feeding
## Compiling our First Module
Compile program
```
javac --module-path mods -d feeding feeding/zoo/animal/feeding/*.java feeding/module-info.java
```

### Note:
- `-d` option specifies the directory to place the class files in.
- After spedifying directory name, we list down all `.java` files to compile.
- `module-path` or `-p` indicates location of any custom module files. In this case, it could be omitted as there are no dependencies. It is a substitute of `classpath` option while working with modular program
- Some alternate forms of above javac command
```
javac -p mods -d feeding feeding/zoo/animal/feeding/*.java feeding/*.java

javac -p mods -d feeding feeding/zoo/animal/feeding/*.java feeding/module-info.java

javac -p mods -d feeding feeding/zoo/animal/feeding/Task.java feeding/module-info.java

javac -p mods -d feeding feeding/zoo/animal/feeding/Task.java feeding/*.java
```

## Running our First Module
Run program
```
java --module-path feeding --module zoo.animal.feeding/zoo.animal.feeding.Task
```
Alternate form of java command
```
java -p feeding -m zoo.animal.feeding/zoo.animal.feeding.Task
```
## Packaging our First Module
Create jar
```
jar -cvf mods/zoo.animal.feeding.jar -C feeding/ .
```
Run program from jar
```
java -p mods -m zoo.animal.feeding/zoo.animal.feeding.Task
```

# Updating our Example for Multiple Modules

## Updating the Feeding Module
See the feeding folder for module zoo.animal.feeding. Uncomment the commented out line in module-info.java

Re-compile:
```
javac -p mods -d feeding feeding/zoo/animal/feeding/*.java feeding/module-info.java
```

Re-package
```
jar -cvf mods/zoo.animal.feeding.jar -C feeding/ .
```

## Creating a Care Module
See the care folder for module zoo.animal.care

Compile:
```
javac -p mods -d care care/zoo/animal/care/details/*.java care/zoo/animal/care/medical/*.java care/module-info.java
```

Package:
```
jar -cvf mods/zoo.animal.care.jar -C care/ .
```

## Creating the Talks Module
See the talks folder for module zoo.animal.talks.

Compile:
```
javac -p mods -d talks talks/zoo/animal/talks/content/*.java talks/zoo/animal/talks/media/*.java talks/zoo/animal/talks/schedule/*.java talks/module-info.java
```
Package:
```
jar -cvf mods/zoo.animal.talks.jar -C talks/ .
```

## Creating the Staff Module
See the staff folder for module zoo.staff.

Compile:
```
javac -p mods -d staff staff/zoo/staff/*.java staff/module-info.java
```
Package:
```
jar -cvf  mods/zoo.staff.jar -C staff/ .
```

### Note:
- Requiring transitively mean, if C required B, then all requires of B are also seeded.

# Diving into the module-info file

## Exporting a Package
In the module-info.java in the talks folder:
1. Uncomment ```exports zoo.animal.talks.content to zoo.staff;```
2. Comment out ```exports zoo.animal.talks.content;```

## Requiring a Module Transitively
In the module-info.java in the care folder:
1. Uncomment ```requires transitive zoo.animal.feeding;```
1. Comment out ```requires zoo.animal.feeding;```

In the module-info.java in the talks folder:
1. Uncomment ```requires transitive zoo.animal.care;```
1. Comment out ```requires zoo.animal.feeding;```
1. Comment out ```requires zoo.animal.care;```

In the module-info.java in the staff folder:
1. Comment out ```requires zoo.animal.feeding;```
1. Comment out ```requires zoo.animal.care;```

## Opening a Package
Don't need to be able to use in examples for this exam

# Creating a Service

### Note:
- 'record' is a special kind of class came in JDK 14 and became standard in JDK 16.
- Records are intended to be a simple, immutable by default, data carrier class.
- They autoimatically generate several useful methods including a constructor, getters, equals(), hashCode() and toString() based on declared fields.
- fields of a record are final and cannot be changed after the record is created. For every parameter a record automatically generates -
    - a private final field
    - a public accessor method (getter but without `get` prefix)
    - a canonical constructor
    - equals(), hashCode() and toString() methods
- Records can not inherit/extend but can implement interfaces
- Not additional state defining allowed apart from what is already done in record header
- ideal for defining DTOs in APIs, simplifying data representation. 

## Declaring the Service Provider Interface
Compile service provider interface module
```
javac -d serviceProviderInterfaceModule serviceProviderInterfaceModule/zoo/tours/api/*.java serviceProviderInterfaceModule/module-info.java
```
Create zoo.tours.api.jar for the service provider interface module
```
jar -cvf mods/zoo.tours.api.jar -C serviceProviderInterfaceModule/ .
```

## Creating a Service Locator

### Note:
learn more about ServiceLoader class of Java

Compile service locator module
```
javac -p mods -d serviceLocatorModule serviceLocatorModule/zoo/tours/reservations/*.java serviceLocatorModule/module-info.java
```
Create zoo.tours.reservations.jar for the service locator module
```
jar -cvf mods/zoo.tours.reservations.jar -C serviceLocatorModule/ .
```

## Invoking from a Consumer
Compile consumer module
```
javac -p mods -d consumerModule consumerModule/zoo/visitor/*.java consumerModule/module-info.java
```
Create zoo.visitor.jar for the visitor module
```
jar -cvf mods/zoo.visitor.jar -C consumerModule/ .
```
Run Tourist class
```
java -p mods -m zoo.visitor/zoo.visitor.Tourist
```

## Adding a Service Provider
Compile service provider module
```
javac -p mods -d serviceProviderModule serviceProviderModule/zoo/tours/agency/*.java serviceProviderModule/module-info.java
```
Create zoo.tours.agency.jar for the service provider module
```
jar -cvf mods/zoo.tours.agency.jar -C serviceProviderModule/ .
```
Run Tourist class
```
java -p mods -m zoo.visitor/zoo.visitor.Tourist
```

# Discovering Modules

## java
Describing a module:
```
java -p mods -d zoo.animal.feeding
```

Alternate form of describing a module
```
java -p mods --describe-module zoo.animal.feeding
```
Listing available modules in JDK:
```
java --list-modules
```
Listing available modules including ours:
```
java -p mods --list-modules
```

Showing Module Resolution:
```
java --show-module-resolution -p feeding -m zoo.animal.feeding/zoo.animal.feeding.Task
```

## jar
Describing a module:
```
jar -f mods/zoo.animal.feeding.jar -d
```
Alternate form of describing a module:
```
jar --file mods/zoo.animal.feeding.jar --describe-module
```

## jmod
Don't need to be able to use in examples for this exam


## jdeps

Compile Dino jar
```
javac zoo/dinos/*.java
```
Create zoo.dino.jar for Dino module
```
jar -cvf zoo.dino.jar .
```
Run jdeps command
```
jdeps zoo.dino.jar
```

Get jdeps summary
```
jdeps -s zoo.dino.jar
jdeps -summary zoo.dino.jar
```

List internal APIs
```
jdeps --jdk-internals zoo.dino.jar
```

# jlink

Create Java runtime image
```
jlink --module-path mods --add-modules zoo.animal.talks --output zooApp
```
