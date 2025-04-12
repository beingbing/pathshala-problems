## ⚙️ Introduction to the Physical Layer (Layer 1 of OSI)

The **Physical Layer** is the **lowest layer** of the OSI model.  
Its job is to **physically transmit raw bits** (0s and 1s) between two devices through some medium.

---

### 🛠 What’s needed for communication?

To send data from one device (peer) to another, we need:

#### 1. **Transmission Medium**  
This is the physical or wireless channel that carries the signals:

- **Electrical signals** (through copper wires)
- **Light signals** (through optical fiber)
- **Radio signals** (wireless)

---

### 🔗 Types of Connections

#### ✅ **Guided (Wired) Media**  
Data flows through a physical path:

- **Twisted Pair Cable** – used in early telephone and LAN networks  
- **Coaxial Cable** – used in cable TV and broadband  
- **Fiber Optic Cable** – very high-speed, long-distance communication (most widely used today)

#### 📡 **Unguided (Wireless) Media**  
No physical connection; data travels through the air:

- **Wi-Fi**
- **Bluetooth**
- **Infrared**, **Radio waves**, etc.

> ⚠ Wireless connections are generally **less secure** and more prone to interference than guided media.

---

### 🔁 Modes of Communication

- **Half-Duplex:** Data flows in **one direction at a time** (e.g., walkie-talkies)
- **Full-Duplex:** Data flows **both ways simultaneously** (e.g., telephone calls)

---

### 🤝 Communication Between Devices

If **both devices are similar** and follow the **same protocols**, communication is straightforward.

But if the devices are **heterogeneous** (e.g., different hardware or operating systems), we need **higher OSI layers** to handle translation and coordination — that's where the **Presentation**, **Session**, and **Application layers** help.
