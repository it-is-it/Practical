```mermaid
graph LR;

  %% User Features %%
  User -->|Registers/Login| Auth;
  User -->|Manages Profile| Profile;
  User -->|Searches Movies| Search;
  User -->|Adds to Watchlist| Watchlist;
  User -->|Rates & Reviews Movies| Review;
  User -->|Follows Users| Follow;
  User -->|Engages in Discussions| Discussion;

  %% Admin Features %%
  Admin -->|Manages Movie Database| ManageMovies;
  Admin -->|Moderates User Content| ModerateContent;

  %% System Components %%
  Auth -->|Handles User Authentication| System;
  Profile -->|Stores User Data| System;
  Search -->|Fetches Movie Data| System;
  Watchlist -->|Updates User Lists| System;
  Review -->|Stores Ratings & Reviews| System;
  Follow -->|Tracks User Connections| System;
  Discussion -->|Manages Conversations| System;
  ManageMovies -->|Updates Movie Records| System;
  ModerateContent -->|Monitors & Moderates| System;

  %% Styling %%
  classDef userFeature fill:#f9f,stroke:#333,stroke-width:2px;
  classDef adminFeature fill:#ff9,stroke:#333,stroke-width:2px;
  classDef systemFeature fill:#9ff,stroke:#333,stroke-width:2px;

  class Auth,Profile,Search,Watchlist,Review,Follow,Discussion userFeature;
  class ManageMovies,ModerateContent adminFeature;
  class System systemFeature;
```
