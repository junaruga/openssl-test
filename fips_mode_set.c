#include <stdio.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>

int main(int argc, char *argv[])
{
    int status = EXIT_SUCCESS;
    int fips_enabled = 0;
    OSSL_LIB_CTX *libctx = NULL;

    fips_enabled = EVP_default_properties_is_fips_enabled(libctx);
    printf("FIPS mode: %d\n", fips_enabled);

    libctx = OSSL_LIB_CTX_new();
    printf("FIPS mode on.\n");
    EVP_default_properties_enable_fips(libctx, 1);

    fips_enabled = EVP_default_properties_is_fips_enabled(libctx);
    printf("FIPS mode: %d\n", fips_enabled);

    printf("FIPS mode off.\n");
    EVP_default_properties_enable_fips(libctx, 0);

    fips_enabled = EVP_default_properties_is_fips_enabled(libctx);
    printf("FIPS mode: %d\n", fips_enabled);
err:
    if (libctx) {
        OSSL_LIB_CTX_free(libctx);
    }
    exit(status);
}