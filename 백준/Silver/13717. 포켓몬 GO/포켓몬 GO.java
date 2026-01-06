// package boj.no13717_oop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();

    public static void main(String[] args) throws IOException {
        List<Pokemon> pokemons = readPokemons(getPokemonCount());
        outputView.printResult(getEvolveResult(pokemons));
    }


    private static int getPokemonCount() throws IOException {
        return inputView.readPokemonCount();
    }

    private static EvolveResult getEvolveResult(List<Pokemon> pokemons) {
        int evolvedCount = 0;
        int maximumEvolve = 0;
        Pokemon maximumEvolvedPokemon = pokemons.get(0);
        for (Pokemon pokemon : pokemons) {
            int evolved = pokemon.howManyEvolve();
            if (evolved > maximumEvolve) {
                maximumEvolve = evolved;
                maximumEvolvedPokemon = pokemon;
            }
            evolvedCount += evolved;
        }
        return new EvolveResult(evolvedCount, maximumEvolvedPokemon);
    }

    private static List<Pokemon> readPokemons(int pokemonCount) throws IOException {
        List<Pokemon> pokemons = new ArrayList<>(pokemonCount);
        for (int i = 0; i < pokemonCount; i++) {
            pokemons.add(inputView.readPokemon());
        }
        return pokemons;
    }

    private static final class EvolveResult {
        private final int evolvedCount;
        private final Pokemon pokemon;

        private EvolveResult(int evolvedCount, Pokemon pokemon) {
            this.evolvedCount = evolvedCount;
            this.pokemon = pokemon;
        }
    }


    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public int readPokemonCount() throws IOException {
            return Integer.parseInt(br.readLine());
        }

        public Pokemon readPokemon() throws IOException {
            String name = br.readLine();

            StringTokenizer values = new StringTokenizer(br.readLine());
            int required = Integer.parseInt(values.nextToken());
            int candies = Integer.parseInt(values.nextToken());

            return new Pokemon(name, required, candies);
        }
    }

    static final class Pokemon {
        private final String name;
        private final int required;
        private final int candies;

        private static final int RETURN_CANDY = 2;


        Pokemon(String name, int required, int candies) {
            this.name = name;
            this.required = required;
            this.candies = candies;
        }

        public int howManyEvolve() {
            int currentCandies = this.candies;
            int count = 0;

            while (currentCandies >= required) {
                int evolveCount = currentCandies / required;
                count += evolveCount;
                currentCandies -= evolveCount * required;
                currentCandies += evolveCount * RETURN_CANDY;
            }
            return count;
        }

        public String getName() {
            return name;
        }
    }

    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(EvolveResult result) throws IOException {
            bw.write(result.evolvedCount + "\n");
            bw.write(result.pokemon.getName());
            bw.flush();
        }

        public void printResult() {
        }
    }
}
