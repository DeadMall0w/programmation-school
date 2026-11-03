
package tests;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.EntityTransaction;
import jakarta.persistence.Persistence;
import java.util.HashMap;
import java.util.Map;
import modele.Service;

public class Test1 {
    public static void main(String[] args) {
        String motDePasse = System.getenv("HOPITAL_DB_PASSWORD");
        if (motDePasse == null) {
            throw new IllegalStateException("Définissez la variable d'environnement HOPITAL_DB_PASSWORD avant le test.");
        }

        Map<String, Object> proprietesConnexion = new HashMap<>();
        proprietesConnexion.put("jakarta.persistence.jdbc.user",
                System.getenv().getOrDefault("HOPITAL_DB_USER", "root"));
        proprietesConnexion.put("jakarta.persistence.jdbc.password", motDePasse);

        final EntityManagerFactory emf = Persistence.createEntityManagerFactory("HopitalPU", proprietesConnexion);
        final EntityManager em = emf.createEntityManager();

        try {
            final EntityTransaction et = em.getTransaction();
            try {
                et.begin();

                Service serv1 = new Service("Cardiologie", "Bat A, 1er étage");
                Service serv2 = new Service("Pneumologie", "Bat B, 1er étage");

                em.persist(serv1);
                em.persist(serv2);
                serv1.setLocalisation("Bat D, 2ème étage");

                et.commit();
                System.out.println("Services persistés : " + serv1 + " ; " + serv2);
            } catch (RuntimeException ex) {
                if (et.isActive()) {
                    et.rollback();
                }
                throw ex;
            }
        } finally {
            if (em.isOpen()) {
                em.close();
            }
            emf.close();
        }
    }
}