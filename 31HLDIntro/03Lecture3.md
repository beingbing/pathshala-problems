# Understanding Web Architecture - Backend

## Client Data Storage and Retrieval

Client data storage and retrieval from the database (DB) happen via the backend, but the client can request data only through the frontend.

client -> frontend -> backend -> storage

The backend provides functionalities to the frontend/client for data storage and updates. These functionalities are exposed as functions available over the internet, known as APIs.

## APIs

Normal functions in a programming language work within the environment of that language. However, backend functions need to be accessible over the internet. Hence, interface using which we can programme our application from internet is called API.

When a client requests an API, the request goes via the DNS, finds backend using IP mapping then looks for the exposed function.

client -> DNS -> ... -> backend -> exposed function (API) -> assigned process starts

APIs typically use JSON format to send data, though plain text can also be used.

### Data Validation and Storage

1. **Validation**: The backend first verifies the validity of the request.
2. **Storage**: The backend then uses the address, username, and password of both the DB and file-system (FS) to establish a connection and store or update the data according to request.

### API Types

APIs can have different types, each serving a specific purpose:
- **GET**: Retrieve data
- **POST**: Create new data
- **PUT**: Update existing data
- **DELETE**: Remove data

### Status Codes

APIs return data along with status codes:
- **2xx**: Success
- **4xx**: Client error (e.g., bad request)
- **5xx**: Server error (backend issue)

## Scaling

As concurrent users increase, scaling becomes necessary across all tiers to handle the load and maintain performance.

### 1. Scaling DB, FS, and Cloud Storage

Issues:
- Large concurrent data storage demands can't be met by a single machine
- Slow data retrieval/access due to the volume
- Physical failure of the DB server (single point of failure)

### 2. Scaling Backend

Issues:
- Handling millions of requests, especially if the DB is slow
- High memory/space usage leading to potential backend failure
- Physical failure of the backend server (single point of failure)

### 3. Scaling Frontend

Issues:
- Handling large numbers of concurrent requests
- Potential slowness if the website size is huge

## Future Lectures

In future lectures, we will address these issues and explore strategies for scaling and optimizing our architecture. Each strategy may introduce new layers to our three-tier architecture and come with its own set of challenges.

> Note: There is no one-size-fits-all solution; it’s always a trade-off. We will approach each issue based on specific scenarios to find the best possible solutions.
