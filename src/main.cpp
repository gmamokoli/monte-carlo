#include <iostream>
#include <random>
#include <omp.h>
#include <chrono>

int main() {
    const long long N = 100000000LL;  // Nombre total de tirages
    long long inside = 0;

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel
    {
        // Générateur aléatoire indépendant par thread
        std::mt19937 rng((unsigned) (omp_get_thread_num() + 1) * (unsigned)time(nullptr));
        std::uniform_real_distribution<double> uni(0.0, 1.0);
        long long local_inside = 0;

        #pragma omp for
        for (long long i = 0; i < N; ++i) {
            double x = uni(rng);
            double y = uni(rng);
            if (x*x + y*y <= 1.0) local_inside++;
        }

        #pragma omp atomic
        inside += local_inside;
    }

    double pi_estimate = 4.0 * static_cast<double>(inside) / static_cast<double>(N);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Estimation de pi : " << pi_estimate << std::endl;
    std::cout << "Temps d'exécution : " << elapsed.count() << " s" << std::endl;
    std::cout << "Threads utilisés : " << omp_get_max_threads() << std::endl;

    return 0;
}
