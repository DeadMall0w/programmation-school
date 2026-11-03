package modele;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import java.util.Locale;
import java.util.Objects;

@Entity
public class Service {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "SERVNO")
    private Long id;

    @Column(name = "NOM", length = 42, unique = true, nullable = false)
    private String nom;

    @Column(name = "LOCALISATION", length = 42, nullable = false)
    private String localisation;

    protected Service() {
    }

    public Service(String nom, String localisation){
        this.nom = normaliser(nom);
        setLocalisation(localisation);
    }

    public Long getId() {
        return id;
    }

    public String getNom() {
        return nom;
    }

    public String getLocalisation() {
        return localisation;
    }

    public void setLocalisation(String localisation) {
        this.localisation = normaliser(localisation);
    }

    private static String normaliser(String valeur) {
        return Objects.requireNonNull(valeur, "La valeur ne peut pas être nulle")
                .trim()
                .toUpperCase(Locale.ROOT);
    }

    @Override
    public boolean equals(Object autre) {
        if (this == autre) {
            return true;
        }
        if (!(autre instanceof Service)) {
            return false;
        }
        Service service = (Service) autre;
        return nom != null && nom.equals(service.nom);
    }

    @Override
    public int hashCode() {
        return nom == null ? 0 : nom.hashCode();
    }

    @Override
    public String toString() {
        return "Service{id=" + id + ", nom='" + nom + "', localisation='" + localisation + "'}";
    }
}
