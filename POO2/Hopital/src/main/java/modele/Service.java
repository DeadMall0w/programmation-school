package modele;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity 
public class Service {
    @Id 
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    //@Column(name = "SERVNO")
    private int id;

    @Column (length = 42, unique = true, nullable = false)
    private String nom;


    @Column (length = 42, unique = true, nullable = false)
    private String localisation;


    // Constructeur par défaut
    public Service(String nom, String localisation){
        this.nom = nom;
        this.localisation = localisation;
    }
    
}
