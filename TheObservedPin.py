 # this code is a possible solution for the problem described in
 # https://gist.github.com/ryunp/3c34aa1bec447f9b0c65c55b915788b9

import pprint as pp

def solution(pin):
    neighbors = {'1': '124',
                 '2': '1235',
                 '3': '236',
                 '4': '1457',
                 '5': '24568',
                 '6': '3569',
                 '7': '478',
                 '8': '57890',
                 '9': '689',
                 '0': '80' }

    rate = 1
    possibilities = dict()
    for n in pin:
        possibilities[n] = neighbors[n]
        rate *= len(neighbors[n])

    result = [''] * rate

    for p in possibilities:
        rate /= len(possibilities[p])
        for j in range(0,len(result)):
            result[j] += possibilities[p][int(j//rate) % len(possibilities[p]) ]

    return result

if __name__ == '__main__':
    pin = input('Enter pin: ')
    pp.pprint(solution(pin))
