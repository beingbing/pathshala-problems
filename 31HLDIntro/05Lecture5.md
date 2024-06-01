## Scalability

Scalability is the ability of a system to handle an increasing load. Load can vary depending on the
application, for example, may include the number of concurrent users, the number of requests per
user, or the size of data processed.

### Measuring Scalability

In system design, it's essential to identify the correct metric to measure load. Scalability is
often evaluated using performance metrics.

### Performance

It measures how quickly a system responds. It can be quantified by metrics like average delay or
the 99th percentile delay. Scalability is measured by the system's ability to maintain acceptable
performance as the number of users increases.

### Steps to Determine Scalability:
1. Define Load and its maximum value in worst situation
2. Define performance mertric in terms of acceptable performance per user.
3. Set a passing percentage criterion (e.g., 90% of users meet acceptable performance decided in 2).
4. Test the system for metric set in 2 against max value of Load declared in 1.
5. If the system meets the criteria set in 3 for the metric set in 2, it is scalable.

### Performance Metrics:
1. **Latency**: Time taken for a request to get a response.
2. **Throughput**: Number of requests that can be handled within a time period.

### Ideal vs. Realistic Scaling

Ideal scaling aims for the best system performance for all concurrent users, which is achieved when
all resources are fully available for each request, achieving minimal latency, with desire of
highest possible throughput. Hence desiring increasing throughput and decreasing latency
simultaneously. However, in reality, as throughput increases, latency also increases because
resources are shared among more requests. Thus, in practice, latency ∝ throughput.

### Balancing Throughput and Latency

Latency refers to the time taken for a single request from a single user to get processed, while
throughput measures the system's performance on a large scale, focusing on the number of requests
it can handle simultaneously.

Good Scaling aims at increasing throughput and good performance per user requires low latency. But,
too low latency can indicate low throughput, meaning the system performs well but on a small scale.

So to scale, latency per request is compromised to an acceptable level, and we strive to achieve
best throughput with that acceptable latency per user. Contrary, We can also define expected
throughput of a system and then determine acceptable performance.

### Defining Acceptable Performance

Latency -> Throughput -> Performance -> Scalability

[comment]: The below steps are unclear, leaving it
1. Start with the best latency, x0
2. Increase latency to a particular value x to achieve a good throughput value.
3. Define acceptable latency per user, latency = x sec/user
4. Set a passing percentage criterion to find throughput, like 0.9y should have latency x/user.
5. Set the scale by defining passing percentage criteria for performance for x users.
6. Declare the scale of the system.

### Methods of Scaling

1. **Horizontal Scaling**: Adding more machines and dividing the load among them.
2. **Vertical Scaling**: Improving or increasing resources of a single machine. This is expensive
and less efficient as there's a finite limit to how much you can scale.

### Summary

To achieve scalability:
- Maximize throughput while maintaining acceptable latency.
- Define performance, acceptable performance, and passing criteria for scalability.
- Use horizontal scaling for more efficient and cost-effective scalability.
