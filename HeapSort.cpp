// HeapSort.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<vector>
#include <utility>
#include <chrono>
using namespace std;
static void heapify(vector<int>& V, int n, int i) {
    int smallest = i;        
    int left = 2 * i + 1;    
    int right = 2 * i + 2;   

    if (left < n && V[left] < V[smallest]) smallest = left;
    if (right < n && V[right] < V[smallest])smallest = right;

    if (smallest != i) {
        swap(V[i], V[smallest]);
        heapify(V, n, smallest);
    }
}
static void buildMinHeap(vector<int>& V) {
    int n = V.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(V, n, i);
}

static void afficher(vector<int>& V)
{
    for (int num : V)
        cout << num << " ";
    cout << endl;
}
int main() {
    vector<int>V;
    cout << "insertion en cours..." << std::endl;
    for (int i = 1000000000; i >= 0; i--)
    {
        int a = rand();
        V.push_back(a);
    }
    cout << "insertion terminé" << std::endl;
    auto start = chrono::high_resolution_clock::now();
    cout << "build min heap encours..." << std::endl;
    buildMinHeap(V);
    cout << "build min heap terminé..." << std::endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Temps d'exécution : " << duration.count() << " ms" << endl;
    return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
