from qiskit import QuantumCircuit, Aer, assemble
import numpy as np
from qiskit.visualization import plot_histogram, plot_bloch_multivector

num_players = 3

def fail_stop_protocol(player_id):
    coin = QuantumCircuit(num_players)

    coin.h(0)

    for qubit in range(num_players - 1):
        coin.cx(qubit,qubit+1)

    coin.draw()