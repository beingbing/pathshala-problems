# Understanding Web Architecture - Databases

## Introduction to Dynamic Data

The two-tier architecture (client and frontend server) is insufficient when dealing with data not
known at development time. Static files are pre-determined, but dynamic data, such as user
information, requires a different approach.

Dynamic data has a known structure but unknown values. For example, a phone number (10 digits) or
a first name (string). To manage this, we use a database system where placeholders are created for
various data types. For instance, a `userProfile` table might have columns for `userName`,
`firstName`, `phoneNumber`, etc.

This database resides on a separate machine called the database server (DB server), which requires
authentication (username and password) for access. Unlike the frontend server, which is publicly
accessible, the DB server is secured due to the sensitive nature of its data.

## Handling Dynamic Files

Dynamic files, such as user profile pictures, are usually large (KB/MB). Storing these in the
database would make it bulky and slow. Instead, these files are stored in a separate file system,
typically cloud-based, like AWS EC2.

## Data Categories

1. **Static Data**: 
   - Stored on the frontend server.
   - Publicly accessible, no security needed.

2. **Dynamic Data**:
   - **Text Data**: 
     - Small in size, frequently accessed, and sensitive.
     - Stored in the database with security layers.
   - **Large Files**: 
     - Images/videos that are large and not immediately needed.
     - Stored in cloud storage.

## Three-Tier Architecture

To prevent clients from directly accessing the DB and file system, a backend layer is introduced.
This layer handles the secure access and authentication required for dynamic data. The architecture
is as follows:

| | | | | | | |
|    -   |    -    |    -     |    -    |    -    |    -    |      -       |
| client | ------> | frontend | ------> | backend | ------> | DB/FS server |
|        | <------ |          | <------ |         | <------ |              |

This forms a three-tier architecture with the backend acting as a security layer. This setup is
also known as MVC (Model-View-Controller) architecture, where:
- **Model**: Data (DB/FS)
- **View**: Frontend
- **Controller**: Backend

This is the most commonly followed architecture today.
