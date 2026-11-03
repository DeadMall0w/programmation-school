
package tests;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.EntityTransaction;
import jakarta.persistence.Persistence;
import modele._Service;

public class Test1 {
    public static void main(String[] args) {
        final EntityManagerFactory emf = Persistence.createEntityManagerFactory("HopitalPU");
        final EntityManager em = emf.createEntityManager();

        try {
            final EntityTransaction et = em.getTransaction();
            try {
                et.begin();

                _Service serv1 = new _Service("Cardiologie", "Bat A, 1er étage");
                _Service serv2 = new _Service("Pneumologie", "Bat B, 1er étage");
                _Service serv3 = new _Service("Urgence", "Bat C, 1er étage");

                em.persist(serv1);
                em.persist(serv2);
                serv1.setLocalisation("Bat D, 2ème étage");

                et.commit();
            } catch (Exception ex) {
                System.out.println("Exception: " + ex);
                if (et.isActive()) {
                    et.rollback();
                }
            }
        } finally {
            if (em != null && em.isOpen()) {
                em.close();
            }
            if (emf != null && emf.isOpen()) {
                emf.close();
            }
        }
    }
}