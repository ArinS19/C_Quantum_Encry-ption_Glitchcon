#include <stdio.h>
#include <oqs/oqs.h>
#include <string.h>

// Helper function to print bytes in hexadecimal
void print_hex(const char *label, const uint8_t *data, size_t length) {
    printf("%s: ", label);
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    OQS_KEM *kem = OQS_KEM_new(OQS_KEM_alg_kyber_512);

    if (kem == NULL) {
        printf("Error: Kyber-512 not available!\n");
        return 1;
    }

    printf("Algorithm: %s\n", kem->method_name);

    uint8_t public_key[kem->length_public_key];
    uint8_t secret_key[kem->length_secret_key];

    OQS_KEM_keypair(kem, public_key, secret_key);
    printf("Key pair generated!\n");

    // Print public and secret keys
    print_hex("Public Key", public_key, kem->length_public_key);
    print_hex("Secret Key", secret_key, kem->length_secret_key);

    uint8_t ciphertext[kem->length_ciphertext];
    uint8_t shared_secret_encap[kem->length_shared_secret];

    OQS_KEM_encaps(kem, ciphertext, shared_secret_encap, public_key);
    printf("Encryption done!\n");

    // Print ciphertext and shared secret after encapsulation
    print_hex("Ciphertext", ciphertext, kem->length_ciphertext);
    print_hex("Shared Secret (Encap)", shared_secret_encap, kem->length_shared_secret);

    uint8_t shared_secret_decap[kem->length_shared_secret];
    OQS_KEM_decaps(kem, shared_secret_decap, ciphertext, secret_key);
    printf("Decryption done!\n");

    // Print shared secret after decapsulation
    print_hex("Shared Secret (Decap)", shared_secret_decap, kem->length_shared_secret);

    if (memcmp(shared_secret_encap, shared_secret_decap, kem->length_shared_secret) == 0) {
        printf("Encryption and decryption successful!\n");
    } else {
        printf("Error: Mismatch in secrets!\n");
    }

    OQS_KEM_free(kem);
    return 0;
}
