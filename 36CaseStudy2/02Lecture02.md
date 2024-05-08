# Capacity Estimation

Designing an Online IDE involves estimating the load and data production to ensure the system
can handle the expected traffic.

### Estimated User Base:
- daily active users: 1,000,000
- if every user make 2 submission daily then 2,000,000 write requests daily ~ 24 req/sec on
rounding off ~ 30 req / sec
- assuming each request taking 2 sec (python code can go upto 10 sec each)

### Data Storage:
- with every submission, - Input file, - Output file, - code file
- restricting each file size to be 1MB, it makes 3MB data / req
- storing every submission for just a few days (assume for 5 days)

### R/W ratio
- It will be a write heavy system.
- Each uniquely submitted code only shared to at max 2 users, so read is very low, so, R:W::1:1
