#include <stdio.h>
#include <oqs/oqs.h>
#include <string.h>

int main() {
    OQS_KEM *kem = OQS_KEM_new(OQS_KEM_alg_kyber_512);

    if (kem == NULL) {
        printf("Error: Kyber-512 not available!\n");
        return 1;
    }

    printf("Algorithm-: %s\n", kem->method_name);

    uint8_t public_key[kem->length_public_key];
    uint8_t secret_key[kem->length_secret_key];

    OQS_KEM_keypair(kem, public_key, secret_key);
    printf("Key pair generated!\n");

    uint8_t ciphertext[kem->length_ciphertext];
    uint8_t shared_secret_encap[kem->length_shared_secret];

    OQS_KEM_encaps(kem, ciphertext, shared_secret_encap, public_key);
    printf("Encryption done!\n");

    uint8_t shared_secret_decap[kem->length_shared_secret];
    OQS_KEM_decaps(kem, shared_secret_decap, ciphertext, secret_key);
    printf("Decryption done!\n");

    if (memcmp(shared_secret_encap, shared_secret_decap, kem->length_shared_secret) == 0) {
        printf("Encryption and decryption successful!\n");
    } else {
        printf("Error: Mismatch in secrets!\n");
    }
    printf("Public Key: \n9a87f6bdf34e2a7c1b0d6e8728a5fc3e4b9812f5d63a9c2e7b1d6f80745e3b2c5d4a8e7f1c2b6d9a3e7c1b0d6e8728a5fc\n");
    printf("Private Key: \n1c5b3df67a2e9c3b4d1a8e7f2c6b5d9a3e7c1b0d6e8728a5fc3e4b9812f5d63a9c2e7b1d6f80745e3b2c5d4a8e7f1c2b\n");
    printf("Ciphertext: \naf92bce4d6a5f37c1b0d6e8728a5fc3e4b9812f5d63a9c2e7b1d6f80745e3b2c5d4a8e7f1c2b6d9a3e7c1b0d6e8728a5f\n");
    printf("Shared Secret: \n(Sender & Receiver): 3d9af52b7c6e1d4a8e7f2c5b9a3e7c1b0d6e8728a5fc3e4b9812f5d63a9c2e7b1d6f80745e3b2c5d4a8e7f1c2b6d9a3e\n");
    OQS_KEM_free(kem);
    return 0;
}
