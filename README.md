# C_Quantum_Encry-ption_Glitchcon
Post-Quantum Blockchain Security Using Kyber-512
🛡️ Project Overview

This project implements Kyber-512, a post-quantum cryptography algorithm, using the liboqs (Open Quantum Safe) library. It demonstrates secure key exchange and encryption resistant to potential quantum computing threats.

📌 Features

Post-Quantum Encryption: Utilizes Kyber-512, a lattice-based Key Encapsulation Mechanism (KEM).

Key Generation: Creates public and private key pairs for secure communication.

Encryption & Decryption: Supports data encryption and decryption using Kyber-512.

Verification: Ensures the integrity of shared secrets after encryption and decryption.

🧑‍💻 How It Works

Initialize Kyber-512 Algorithm: Sets up the algorithm using the Open Quantum Safe (OQS) library.

Key Pair Generation: Generates a public and secret key.

Encrypt Data: Encapsulates a shared secret and encrypts it using the public key.

Decrypt Data: Decapsulates the shared secret using the secret key.

Validation: Verifies the shared secret after encryption and decryption.

📂 Project Structure

|-- kyber_demo.c    # Main source code
|-- CMakeLists.txt  # Build configuration
|-- README.md       # Project documentation

🔧 Prerequisites

C Compiler (gcc/clang)

liboqs Library (Open Quantum Safe)

CMake (for building the project)
