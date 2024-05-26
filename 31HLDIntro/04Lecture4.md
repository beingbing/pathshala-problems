# Key Principles of System Design

Before discussing specific issues and solutions in a given scenario, we need to understand some key
concepts. Good systemic design in software relies on three basic principles:

1. **Reliability**: The system provides valid responses in every situation.
2. **Scalability**: The system can handle a certain load and manage multiple requests
simultaneously.
3. **Maintainability**: The system is easy to maintain, allowing for new features to be added and
issues to be debugged efficiently.

## Reliability

Reliability ensures that the application/software continues to run and provide valid outputs
regardless of circumstances. Ideally, even in catastrophic situations, the system should remain
operational and fault-tolerant.

**Fault Types**:

1. **Hardware Faults**:
   - Examples: Power outages, connectivity loss, hardware failures (e.g., hard disk/RAM failure).
   - Impact: These faults can cause request failures.
   - Solutions: Avoid single points of failure by using multiple servers and strategies like load
   balancing and replication.

2. **Software Faults**:
   - Examples: Code/configuration bugs, application malfunctions.
   - Impact: A single bug shouldn't bring down the entire system.
   - Solutions:
     - Thoroughly test code with good test coverage.
     - Continuously monitor servers.
     - Handle exceptions and errors gracefully to prevent server crashes.

By focusing on reliability, we can ensure that our system remains robust and functional, even in
the face of faults.
