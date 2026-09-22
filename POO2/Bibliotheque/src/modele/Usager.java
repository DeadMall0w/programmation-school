package src.modele;

import java.sql.Date;
import java.time.LocalDate;
import java.util.Objects;

public class Usager {
    private int id;
    private String nom;
    private String prenom;
    private String adresse;
    private Date dateNaissance;

    // Constructeur par données complet
    public Usager(int id, String nom, String prenom, String adresse, Date dateNaissance) {
        this.id = id;
        this.nom = nom;
        this.prenom = prenom;
        this.adresse = adresse;
        this.dateNaissance = dateNaissance;
    }

    // Getters et Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public String getAdresse() {
        return adresse;
    }

    public void setAdresse(String adresse) {
        this.adresse = adresse;
    }

    public Date getDateNaissance() {
        return dateNaissance;
    }

    public void setDateNaissance(Date dateNaissance) {
        this.dateNaissance = dateNaissance;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Usager usager = (Usager) o;
        // Deux usagers sont identiques si leur identifiant ou leur triplet (nom, prénom, adresse) correspond
        return id == usager.id || 
               (Objects.equals(nom, usager.nom) && 
                Objects.equals(prenom, usager.prenom) && 
                Objects.equals(adresse, usager.adresse));
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, nom, prenom, adresse);
    }

    @Override
    public String toString() {
        return prenom + " " + nom + " (ID: " + id + ", né(e) le " + dateNaissance + ", adresse: " + adresse + ")";
    }
}