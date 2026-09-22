package src;
import java.sql.SQLException;
import java.util.List;
import java.util.Set;

import src.modele.*;
import src.requete.*;

public class App {
    public static void main(String[] args) {
        RequeteBiblio re;
        System.out.println("Hello, world !");
        
        try {
            re = new RequeteBiblio();
        } catch (Exception e) {
            System.err.println("Erreur lors de la connexion à la BDD, fin du programme");
            return ;
        }

        try {
            int i = 0;
            List<Usager> u = re.getUsagersParNom("alice");
        
            for (Usager usager : u) {
                System.out.println(usager.getNom() + " - " + usager.getPrenom());
            }
        } catch (Exception e) {
            System.err.println("Erreur lors de la recherche des usagers : " + e.getMessage());
        }
        // try {
        //     int i = 0;
        //     Set<Livre> livres = re.getLivresEmpruntes();
        //     for (Livre livre : livres) {
        //         System.out.println(livre.getTitre());
        //         i++;
        //     }

        //     System.out.println(i);


        // } catch (Exception e) {
        //     // TODO: handle exception
        //     System.err.println("Erreur lors de la récupération des livres !" + e.getMessage());

        // }        
        try {    
            List<Emprunt> retards = re.getEmpruntsEnRetard();
            
            for (Emprunt emp : retards) {
                System.out.println(emp);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Livre livreARendre = new Livre("9780441363940", "Dune", "Frank Herbert", "Chilton Books", 412, 1965);

            boolean succes = re.rendreLivre(livreARendre);

            if (succes) {
                System.out.println("Le livre a bien été retourné !");
            } else {
                System.out.println("Aucun emprunt en cours trouvé pour ce livre.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            List<Usager> usagersAlice = re.getUsagersParNom("Alice");
            List<Livre> livres = re.getLivresTriesParTitre();

            if (usagersAlice.isEmpty() || livres.isEmpty()) {
                System.out.println("Impossible de tester l'emprunt : Alice ou aucun livre introuvable.");
            } else {
                Usager alice = usagersAlice.get(0);
                Livre livre = livres.get(0);
                boolean succes = re.emprunterLivre(livre, alice);

                if (succes) {
                    System.out.println("Emprunt réussi : " + alice.getPrenom() + " "
                            + alice.getNom() + " emprunte « " + livre.getTitre() + " ».");
                } else {
                    System.out.println("L'emprunt n'a pas été enregistré.");
                }
            }
        } catch (SQLException e) {
            System.err.println("Erreur lors de l'emprunt : " + e.getMessage());
        }
    }
}