package src.requete;

import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.sql.Statement;
import java.time.LocalDate;

import src.modele.*; 

public class RequeteBiblio {
    private Connection connexionBdd;

    public RequeteBiblio() throws SQLException {
        String urlBDD = "jdbc:mysql://localhost:3306/POO2_TP1"; // ou le nom de ta base
        String utilisateur = "rapha";
        String motDePasse = "Rapha_2026!";

        this.connexionBdd = DriverManager.getConnection(urlBDD, utilisateur, motDePasse);
        System.out.println("OK - Connexion à la BDD");
    }

    public Connection getConnexionBdd() {
        return this.connexionBdd;
    }

    public List<Livre> getLivresTriesParTitre() throws SQLException {
        List<Livre> listeLivres = new ArrayList<>();
        
        String requete = "SELECT isbn, titre, auteur, editeur, nb_pages, annee_publication FROM livre ORDER BY titre ASC";

        Statement statement = this.connexionBdd.createStatement();
        ResultSet result = statement.executeQuery(requete);

        while (result.next()) {
            String isbn = result.getString("isbn");
            String titre = result.getString("titre");
            String auteur = result.getString("auteur");
            String editeur = result.getString("editeur");
            int nbPages = result.getInt("nb_pages");
            int annee = result.getInt("annee_publication");

            Livre l = new Livre(isbn, titre, auteur, editeur, nbPages, annee);
            listeLivres.add(l);
        }

        result.close();
        statement.close();

        return listeLivres;
    }

    public Set<Livre> getLivresEmpruntes() throws SQLException{
        Set<Livre> listeLivres = new HashSet<Livre>();

        String requete = "SELECT isbn, titre, auteur, editeur, nb_pages, annee_publication FROM livre JOIN emprunt ON fk_isbn = isbn WHERE date_retour IS NULL";

        Statement statement = this.connexionBdd.createStatement();
        ResultSet result = statement.executeQuery(requete);

        while (result.next()) {
            String isbn = result.getString("isbn");
            String titre = result.getString("titre");
            String auteur = result.getString("auteur");
            String editeur = result.getString("editeur");
            int nbPages = result.getInt("nb_pages");
            int annee = result.getInt("annee_publication");

            Livre l = new Livre(isbn, titre, auteur, editeur, nbPages, annee);
            listeLivres.add(l);
        }

        result.close();
        statement.close();

        return listeLivres;
    }

        public List<Livre> getLivresParMotCle(String motCle) throws SQLException {
            List<Livre> livresTrouves = new ArrayList<Livre>();

            String requete = "SELECT isbn, titre, auteur, editeur, nb_pages, annee_publication "
                        + "FROM livre "
                        + "WHERE UPPER(titre) LIKE ? "
                        + "   OR UPPER(auteur) LIKE ? "
                        + "   OR UPPER(editeur) LIKE ?";

            PreparedStatement prepStatement = this.connexionBdd.prepareStatement(requete);

            String motifRecherche = "%" + motCle.toUpperCase() + "%";

            prepStatement.setString(1, motifRecherche); 
            prepStatement.setString(2, motifRecherche); 
            prepStatement.setString(3, motifRecherche); 

            ResultSet result = prepStatement.executeQuery();

            while (result.next()) {
                String isbn = result.getString("isbn");
                String titre = result.getString("titre");
                String auteur = result.getString("auteur");
                String editeur = result.getString("editeur");
                int nbPages = result.getInt("nb_pages");
                int annee = result.getInt("annee_publication");

                Livre l = new Livre(isbn, titre, auteur, editeur, nbPages, annee);
                livresTrouves.add(l);
            }

            result.close();
            prepStatement.close();

            return livresTrouves;
    }

    public List<Usager> getUsagersParNom(String nom) throws SQLException {
        List<Usager> usagers = new ArrayList<Usager>();

        String requete ="SELECT * FROM usager WHERE UPPER(nom) LIKE ? OR UPPER(prenom) LIKE ?";
        
        PreparedStatement prep = this.connexionBdd.prepareStatement(requete);

        String motifRecherche = "%" + nom.toUpperCase() + "%";

        prep.setString(1, motifRecherche); 
        prep.setString(2, motifRecherche);
        
        ResultSet result = prep.executeQuery();

        while (result.next()) {
            int id_usager = result.getInt("id_usager");
            String _nom = result.getString("nom");
            String prenom = result.getString("prenom");
            String adresse = result.getString("adresse");
            Date date = result.getDate("date_naissance");

            Usager u = new Usager(id_usager, _nom, prenom, adresse, date);
            usagers.add(u);
        }

        result.close();
        prep.close();

        return usagers;
    }

    // Question 14
    public List<Emprunt> getEmpruntsEnRetard(int nbJoursRetard) throws SQLException {
        List<Emprunt> empruntsEnRetard = new ArrayList<>();

        // Requête avec jointure sur les 3 tables pour hydrater complètement Livre et Usager
        String requete = "SELECT e.id_emprunt, e.date_emprunt, e.date_retour, "
                       + "       l.isbn, l.titre, l.auteur, l.editeur, l.nb_pages, l.annee_publication, "
                       + "       u.id_usager, u.nom, u.prenom, u.adresse, u.date_naissance "
                       + "FROM emprunt e "
                       + "JOIN livre l ON e.fk_isbn = l.isbn "
                       + "JOIN usager u ON e.fk_id_usager = u.id_usager "
                       + "WHERE e.date_retour IS NULL "
                       + "  AND DATEDIFF(CURRENT_DATE(), e.date_emprunt) > ?";

        PreparedStatement prep = this.connexionBdd.prepareStatement(requete);
        prep.setInt(1, nbJoursRetard);

        ResultSet result = prep.executeQuery();

        while (result.next()) {
            int idUsager = result.getInt("id_usager");
            String nom = result.getString("nom");
            String prenom = result.getString("prenom");
            String adresse = result.getString("adresse");
            Date dateNaiss = result.getDate("date_naissance");
            Usager usager = new Usager(idUsager, nom, prenom, adresse, dateNaiss);

            String isbn = result.getString("isbn");
            String titre = result.getString("titre");
            String auteur = result.getString("auteur");
            String editeur = result.getString("editeur");
            int nbPages = result.getInt("nb_pages");
            int annee = result.getInt("annee_publication");

            Livre livre = new Livre(isbn, titre, auteur, editeur, nbPages, annee);

            
            int idEmprunt = result.getInt("id_emprunt");
            LocalDate dateEmp = result.getDate("date_emprunt").toLocalDate();
            LocalDate dateRet = (result.getDate("date_retour") != null) 
                              ? result.getDate("date_retour").toLocalDate() 
                              : null;

            Emprunt emprunt = new Emprunt(idEmprunt, livre, usager, dateEmp, dateRet);
            empruntsEnRetard.add(emprunt);
        }

        result.close();
        prep.close();

        return empruntsEnRetard;
    }


    public List<Emprunt> getEmprunts() throws SQLException {
        List<Emprunt> emprunts = new ArrayList<>();

        // Requête avec jointure sur les 3 tables pour hydrater complètement Livre et Usager
        String requete = "SELECT e.id_emprunt, e.date_emprunt, e.date_retour, "
                       + "       l.isbn, l.titre, l.auteur, l.editeur, l.nb_pages, l.annee_publication, "
                       + "       u.id_usager, u.nom, u.prenom, u.adresse, u.date_naissance "
                       + "FROM emprunt e "
                       + "JOIN livre l ON e.fk_isbn = l.isbn "
                       + "JOIN usager u ON e.fk_id_usager = u.id_usager ";

        PreparedStatement prep = this.connexionBdd.prepareStatement(requete);

        ResultSet result = prep.executeQuery();

        while (result.next()) {
            int idUsager = result.getInt("id_usager");
            String nom = result.getString("nom");
            String prenom = result.getString("prenom");
            String adresse = result.getString("adresse");
            Date dateNaiss = result.getDate("date_naissance");
            Usager usager = new Usager(idUsager, nom, prenom, adresse, dateNaiss);

            String isbn = result.getString("isbn");
            String titre = result.getString("titre");
            String auteur = result.getString("auteur");
            String editeur = result.getString("editeur");
            int nbPages = result.getInt("nb_pages");
            int annee = result.getInt("annee_publication");

            Livre livre = new Livre(isbn, titre, auteur, editeur, nbPages, annee);

            
            int idEmprunt = result.getInt("id_emprunt");
            LocalDate dateEmp = result.getDate("date_emprunt").toLocalDate();
            LocalDate dateRet = (result.getDate("date_retour") != null) 
                              ? result.getDate("date_retour").toLocalDate() 
                              : null;

            Emprunt emprunt = new Emprunt(idEmprunt, livre, usager, dateEmp, dateRet);
            emprunts.add(emprunt);
        }

        result.close();
        prep.close();

        return emprunts;
    }
    public List<Emprunt> getEmpruntsEnRetard() throws SQLException {
        return getEmpruntsEnRetard(20);
    }

    public boolean rendreLivre(Livre livre) throws SQLException {
        String requete = "UPDATE emprunt SET date_retour = CURRENT_DATE() WHERE fk_isbn = ? AND date_retour IS NULL";

        PreparedStatement prep = this.connexionBdd.prepareStatement(requete);

        prep.setString(1, livre.getIsbn());

        int lignesModifiees = prep.executeUpdate();

        prep.close();

        // astuce trouvé par IA (pour éviter de multiple requête pour valider la MAJ du champ)
        return lignesModifiees > 0;
    }

    public boolean emprunterLivre(Livre l, Usager u) throws SQLException {
        String requete = "INSERT INTO emprunt(date_emprunt, fk_id_usager, fk_isbn) VALUES (CURRENT_DATE(), ?, ?)";

        PreparedStatement prep = this.connexionBdd.prepareStatement(requete);

        prep.setInt(1, u.getId());
        prep.setString(2, l.getIsbn());

        int lignesAjoutees = prep.executeUpdate();
        prep.close();

        return lignesAjoutees > 0;
    }

}
