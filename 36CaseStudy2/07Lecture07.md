# Containerisation

Containerization, a lightweight form of virtualization, represents process of creating and running
containers.

Three stages of a container -> config-text-file -> Image -> container-runtime

**A container-runtime is a sandbox for a process**. Sandbox: process have a separate namespace and
cgroups. Each container has only one main process, which only knows about processes existing within
the same container, like, threads it initiated or running daemon process, its life-cycle is tied to
container. Starting/stoping container will start/stop the process and vice versa. When a container
is instantiated, nothing is installed on the OS, so when the container is removed, it leaves behind
a clean environment without any leftover files.

Note: cgroups limit how much resources a process can use. It provides metering and limiting on
- memory - CPU - block I/O - etc., as well as access control.

Note: Daemon process - these are suffixed by 'd'. The way involuntary muscles are to humans,
daemon processes are to computers. They get started when a computer starts, ensure smooth
working of computer and do not need user interaction.

Why Containers conceptualised ?

To interact with Hardware we will be making system calls to Host OS kernel. The libraries that our
application uses to make those calls are written differently for different OS. so,
`VM (or, dev env) = dev OS kernel + dev OS System libs + developer-code`

Hence, wrapping application-code and its dependent system-libs into an entity, called Image. Which
is just a binary representation of runtime state of a container existing in FS. It is a template
with instructions for creating container's runtime environment. Images also establish a
parent-child relationship through layering, allowing modification of pre-existing Image to get
customized version, often referred to as Snapshot. Also, we can instantiate a parent Image into
a container-runtime, log in using shell, make modifications, and commit the changes into a new
Image. In analogy, Image is like a Class, and container-runtime is like a runtime Object.

Note: BusyBox is a set of commands used by Linux/Unix, which are not natively available.

How to build an Image ?

Referring to Docker, we create a DockerFile, which is a text-file defining an environment. Each
DockerFile begins by importing a pre-existing Image and adding custom configurations. Using
docker-build command, we process the DockerFile to create an Image.

How to use Docker ?

Docker is installed on a machine. It follows client-server architecture, where the Docker-client is
the user-interface, and the Docker-daemon is the server. The Docker-host is the OS application
where Daemon runs. Docker-containers are isolated, lightweight, and portable environments capable
of running on any Host. Users employ Client to instruct Daemon to build, run, and manage
Containers. When a new Host is started, it connects to Docker-hub over Internet to pull/push Image
configurations. It only transfers parts of Image tree not present in the cache. Host can run
different images simultaneously, isolated from each other, like a browser running multiple tabs.
Each Container has its own root, unaware of others, having an independent process running. The
Daemon creates and manages Containers and Images stored on the Host.

Client can configure Host infrastructure too, like adjusting network/storage configuration:
- For network, Client can create a network for Containers to communicate internally or assign
network-ports for external communication.
- For Storage, Docker-volume can be created for persistent storage. Containers are assigned Volumes
to retain data even if they go down, preventing total information loss.

Note: Docker-hub is a cloud-based registry to store and share Docker images. It can contain
images with public or private access.

Note: Docker-host can be physical machines, virtual machines, or cloud-based instances but will
always be with Private access.

Note: Port-forwarding, also known as port-mapping, is a network address translation (NAT) technique
that allows a communication request to be redirected from one address and port number combination
to another while passing through a network gateway.

Note: When you run docker-build command, Client sends a build Image request to Daemon from a
Dockerfile. docker-run command sends a request to create and run Container to Daemon from Image.
docker-stop command sends a request to stop a running Container.

What is Kubernetes ?

A tool for managing and automating containerized workloads in the cloud. It orchestrates
infrastructure to handle changing workloads by scaling containers horizontally across
multiple machines and handling complexities like networking, secret management, and storage.

Designed for high availability, it can maintain replica-sets for microservices and ensures disaster
recovery by replacing failed machines without losing application state in a system
deployed on Kubernetes called Cluster comprised of mulitple Worker Nodes and one Master Node.

The Control-plane, the brain behind it, manages the cluster, deployed on Master (although it can be
installed on a worker Node as well, it's ideally kept separate). It exposes an API server (also a
container) for internal and external requests, the only entry point into the Cluster. All Client
communication via UI, API or CLI are received here. It has Schedular to assign node to newly
created pods, a Control-Manager responsible for managing the cluster's state, and ETCD, a key-value
database storing the cluster's current state.

Kubernetes manages Nodes, alias for machines, physical or virtual, each running Kubelet, a tiny
application, to communicate with Control-plane, and each Node having multiple Pods, the smallest
deployable units with own IP address.

One pod per container, except when a main container needs a helper container. The pod is
responsible for managing the container's life-cycle and health. However, pods are ephemeral,
meaning they frequently shut down and are replaced with new ones, which can lead to lost
communication as new pods often have different IP addresses.

To address this issue, Kubernetes has Service, alternative to dynamic IP address. Each pod is
associated with a Service, ensuring that communication channels remain intact even if a pod dies.
When a new pod is ready, it gets attached to the same Service by kube-proxy, which maintains a
network routing table mapping Service IP addresses to pod IP addresses. Services have two main
functions: providing a permanent IP address for communication and acting as a load balancer,
allowing them to handle communication for multiple pods. To avoid downtime, replicas of a container
are mapped to the same Service IP. This ensures that even if a pod fails, incoming requests can
still be handled by the replica.

Service is of two types: External and Internal. External Services handle requests from outside the
cluster, while Internal Services handle requests from within. However, accessing External Services
via IP addresses and port numbers isn't convenient.
External Service URL - http://\<Node IP address>:\<Port no of service on which pod is listening>

To address this, we use Ingress to map these services to domain names with HTTPS protocol. Making
external request to get consumed on Ingress, which then depending on mapping forwards to the
designated External Service.

ConfigMap in Kubernetes store external configurations for application. It contain key-value pairs
where keys are used in the application code, and values represent real data. By connecting
ConfigMap to pods, we can provide real values to the keys referenced in the application code
without needing to rebuild Image. Simply updating the ConfigMap and redeploying the container will
propagate the changes to the pod.

Sensitive data in ConfigMap may require additional security measures. Kubernetes provides Secret
for this purpose. Secret is similar to ConfigMap but store values in Base-64 Encoded format. Keys
from both ConfigMap and Secret can be used as environment variables or in properties files for
added security.

Kubernetes uses Volumes for data storage, which attach physical storage or hard drives to pods.
This storage can be local to the server node or remote. With Volumes, data in a pod with a database
container persists even when the pod is restarted. However, Kubernetes doesn't directly manage data
persistence. Volumes are treated as external components plugged into the cluster, so it's our
responsibility to replicate and maintain them, along with managing the associated hardware.

We define desired state of our cluster like, replicas, exposed ports, persistent volumes, etc., in
the form of objects in .yaml/JSON file. Every request to Kubernetes contains configuration for
Deployment component, which is a template for creating pods. As pods are an abstraction layer over
containers, Deployment is an abstraction of pods. Kubernetes automatically provisions
and scales containers based on these files, maintaining their desired state and health. Client
requests are declarative, and Control Manager strives to meet the declared desired state.

DB pods cannot be replicated using Deployment because each DB container maintains a state. Instead,
StatefulSet is used for creating stateful apps or DB pods, ensuring adherence to ACID principles.
However, deploying stateful components with StatefulSet in Kubernetes can be complex, so they are
often hosted outside the cluster to avoid complications.

Note: Access to Cluster can be lost if Master Node goes down, hence production Cluster normally has
multiple Master Nodes.
