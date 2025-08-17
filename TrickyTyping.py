# https://www.pclassic.org/static/media/PClassic2023fProblems.62ca5b098f5a6f3af47d.pdf

# distancia de Chebyshev
def dist(p0, p1):
    return max(abs(p0[0]-p1[0]) , abs(p0[1] - p1[1]))

# cria um mapa de referencias letra=coordenada
def gera_tabuleiro(tab):
    d = {}

    for i in range(5):
        for j in range(5):
            d[tab[i][j]] = (i,j)
    return d


'''
// versao C++
map<char, pair<int, int>> gera_tabuleiro(char mapa[5][5]){
    map<char, pair<int, int>> d;

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            d[tab[i][j]] = {i, j}
    return d;      
}
'''  

# gera o vetor de posicoes no mapa
def calcula_letras(palavra, mapa):
    pos = []
    for l in palavra:
        pos.append(mapa[l])
    return pos

def menor_distancia(lh, rh, d, palavra):

    n = len(palavra)
    distancias = [0]*2**n
    
    combinacoes = []
    for i in range(2**n):  # de 0 até 15
        combinacoes.append(f"{i:0{n}b}")   # imprime em binário com 4 dígitos


    '''
    vector<string> combinacoes;

    for (int i = 0; i < (1 << n); i++) 
        combinacoes.push_back(bitset<10000>(i).to_string().substr(10000 - n));

    '''

    olh, orh = lh, rh
    for i in range(len(combinacoes)):
        lh, rh = olh, orh
        distancia = 0
        for j in range(len(palavra)):
            
            l = palavra[j]
            if combinacoes[i][j] == '0':
                distancia += dist(lh, d[l])+1
                lh = d[l]
            else:
                distancia += dist(rh, d[l])+1
                rh = d[l]
        distancias[i] = distancia
    return min(distancias)

mapa = []
for i in range(5):
    mapa.append(input())

lh, rh = input().split()

palavra = input()

d = gera_tabuleiro(mapa)
lh = d[lh]
rh = d[rh]

print(menor_distancia(lh, rh, d, palavra))
