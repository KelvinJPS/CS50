# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    counts = {}
    # Read teams from  a file
    filename = sys.argv[1]
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            teams.append(row)
    # Populate counts dictionary with the name of teams and the number of wins  which is set initially to  zero 
    for team in teams: 
        counts[team["team"]] = 0
    # Simulate N tournaments and keep track of win counts
    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1 
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = int(team1["rating"])
    rating2 = int(team2["rating"])
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    winners = simulate_round(teams)
    if len(winners) == 1:
        return winners[0].get("team")

    elif len(winners) > 1:
        return simulate_tournament(winners)


if __name__ == "__main__":
    main()
