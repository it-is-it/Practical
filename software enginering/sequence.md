```mermaid
sequenceDiagram
    participant User
    participant System
    participant Database
    participant Admin

    User->>System: Register/Login
    System->>Database: Validate Credentials
    Database-->>System: Return Status
    System-->>User: Login Success/Failure

    User->>System: Search for Movies
    System->>Database: Fetch Movie Data
    Database-->>System: Return Movie List
    System-->>User: Display Search Results

    User->>System: Add Movie to Watchlist
    System->>Database: Update Watchlist
    Database-->>System: Confirm Addition
    System-->>User: Movie Added Successfully

    User->>System: Submit Review & Rating
    System->>Database: Store Review & Rating
    Database-->>System: Confirm Submission
    System-->>User: Review Submitted

    User->>System: Follow Another User
    System->>Database: Update Follow List
    Database-->>System: Confirm Follow Action
    System-->>User: Follow Successful

    Admin->>System: Add/Update/Delete Movie
    System->>Database: Modify Movie Database
    Database-->>System: Confirm Changes
    System-->>Admin: Action Successful

    Admin->>System: Moderate User Reviews
    System->>Database: Approve/Remove Content
    Database-->>System: Confirm Action
    System-->>Admin: Moderation Completed
```
