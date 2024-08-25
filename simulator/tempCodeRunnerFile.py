from scipy.stats import norm
import matplotlib.pyplot as plt 
import numpy as np
import math
import textwrap

randomNumGen = np.random.default_rng()

def aBernoulliExperiment(randomNumGen, bernoulliParam_p=0.5, numRepeatsOfExp=1, numTrialsInAnExp=20, profitLoss=[1,0]):
    repeatIndex = 0
    randomNumGen = np.random.default_rng()

    observation = np.ones((numRepeatsOfExp, numTrialsInAnExp))

    observation = randomNumGen.random((numRepeatsOfExp, numTrialsInAnExp))

    index_ge1 = np.less_equal(observation, bernoulliParam_p)

    observation[index_ge1] = profitLoss[0]
    observation[np.invert(index_ge1)] = profitLoss[1]

    return observation

v_numTrialsInAnExp = 20
v_numRepeatsOfExp =1
v_bernoulliParam_p = 0.2
observation = aBernoulliExperiment(np.random.default_rng(1236), bernoulliParam_p=v_bernoulliParam_p, numRepeatsOfExp = v_numRepeatsOfExp, numTrialsInAnExp = v_numTrialsInAnExp, profitLoss=[1,0])

fig, ax1 = plt.subplots()

trial_numbers = range(1, v_numTrialsInAnExp+1)
counts = np.sum(observation, axis=0)

ax1.bar(trial_numbers, counts, color="blue")
ax1.set_xlabel('Trial number')
ax1.set_ylabel('Count')
ax1.set_xticks(trial_numbers)
ax1.set_yticks([0, 1])
ax1.set_yticklabels(['T', 'H'])
ax1.set_title('Coin toss outcomes for {} trials'.format(v_numTrialsInAnExp))

plt.show()