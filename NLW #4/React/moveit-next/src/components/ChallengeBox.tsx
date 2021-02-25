import { useContext } from 'react';
import { ChallengesContext } from '../contexts/ChallengesContext';
import styles from '../styles/components/ChallengeBox.module.css'

export function ChallengeBox() {
    const {activeChallenger , resetChallenge} = useContext(ChallengesContext);

    return(        
        <div className={styles.challengeBoxContainer}>
            {activeChallenger ? (
                <div className = {styles.challengeActive}>
                    <header>Ganhe {activeChallenger.amount}xp</header>
                    <main>
                        <img src={`icons/${activeChallenger.type}.svg`} />
                        <strong>Novo desafio</strong>
                        <p>{activeChallenger.description}</p>
                    </main>

                    <footer>
                        <button 
                            type = "button"
                            className={styles.challengeFailButton}
                            onClick= {resetChallenge}
                        >
                            Falhei
                        </button>
                        <button 
                            type = "button"
                            className={styles.challengeSucceededButton}
                        >
                            Completei
                        </button>
                    </footer>
                </div>
            ) : (
                <div className = {styles.challengeNotActive}>
                    <strong>Finalize um ciclo para receber um desafios</strong>
                    <p>
                        <img src="icons/level-up.svg" alt="level UP"/>
                        Avance de level completando desafios.
                    </p>
                </div>
            ) }
        </div>
    )
}