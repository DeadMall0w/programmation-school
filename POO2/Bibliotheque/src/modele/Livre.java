package src.modele;

public class Livre {
    private String isbn;
    private String titre;
    private String auteur;
    private String editeur;
    private int nbPages;
    private int anneePublication;

    // Constructeur par données (demandé Question 8)
    public Livre(String isbn, String titre, String auteur, String editeur, int nbPages, int anneePublication) {
        this.isbn = isbn;
        this.titre = titre;
        this.auteur = auteur;
        this.editeur = editeur;
        this.nbPages = nbPages;
        this.anneePublication = anneePublication;
    }

    

    public String getIsbn() {
        return isbn;
    }



    public String getTitre() {
        return titre;
    }



    public String getAuteur() {
        return auteur;
    }



    public String getEditeur() {
        return editeur;
    }



    public int getNbPages() {
        return nbPages;
    }



    public int getAnneePublication() {
        return anneePublication;
    }



    @Override
    public String toString() {
        return titre + " (" + auteur + ", " + anneePublication + ")";
    }
}