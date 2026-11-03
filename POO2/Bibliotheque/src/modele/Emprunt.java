package src.modele;

import java.time.LocalDate;
import java.util.Objects;

public class Emprunt {
    private int id;
    private Livre livre;           // Référence directe vers l'objet Livre
    private Usager usager;         // Référence directe vers l'objet Usager
    private LocalDate dateEmprunt;
    private LocalDate dateRetour;  // null si le livre n'a pas encore été retourné

    public Emprunt(int id, Livre livre, Usager usager, LocalDate dateEmprunt, LocalDate dateRetour) {
        this.id = id;
        this.livre = livre;
        this.usager = usager;
        this.dateEmprunt = dateEmprunt;
        this.dateRetour = dateRetour;
    }

    public Emprunt(int id, Livre livre, Usager usager, LocalDate dateEmprunt) {
        this(id, livre, usager, dateEmprunt, null);
    }

    // Getters et Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Livre getLivre() {
        return livre;
    }

    public void setLivre(Livre livre) {
        this.livre = livre;
    }

    public Usager getUsager() {
        return usager;
    }

    public void setUsager(Usager usager) {
        this.usager = usager;
    }

    public LocalDate getDateEmprunt() {
        return dateEmprunt;
    }

    public void setDateEmprunt(LocalDate dateEmprunt) {
        this.dateEmprunt = dateEmprunt;
    }

    public LocalDate getDateRetour() {
        return dateRetour;
    }

    public void setDateRetour(LocalDate dateRetour) {
        this.dateRetour = dateRetour;
    }

    // Méthode utilitaire pour savoir si l'emprunt est toujours en cours
    public boolean estEnCours() {
        return this.dateRetour == null;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Emprunt emprunt = (Emprunt) o;
        return id == emprunt.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }

    @Override
    public String toString() {
        String retourStr = (dateRetour != null) ? dateRetour.toString() : "Non retourné";
        return "Emprunt n°" + id + " : " + livre.getTitre() + " emprunté par " + usager.getPrenom() + " " + usager.getNom()
                + " le " + dateEmprunt + " (Retour: " + retourStr + ")";
    }
}