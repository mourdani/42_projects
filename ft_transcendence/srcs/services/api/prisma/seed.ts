// prisma/seed.ts

import { PrismaClient } from '@prisma/client';
import { Public } from '@prisma/client/runtime';

// initialize Prisma Client
const prisma = new PrismaClient();

async function main() {
	// add achievements to database if not already there! Important!!!
	const achievements = await prisma.achievement.findMany();
	await prisma.achievement.upsert({
		where: {
			achievement_id: 1,
		},
		update: {},
		create : {
			achievement_id: 1,
			name: "Baby steps",
			description: "You have played your first game of Pong!",
			play_requirement: 1
	}});

	await prisma.achievement.upsert({
		where: {
			achievement_id: 2,
		},
		update: {},
		create : {
			achievement_id: 2,
			name: "Loser",
			description: "You have lost 5 games.",
			lose_requirement: 5
	}});

	await prisma.achievement.upsert({
		where: {
			achievement_id: 3,
		},
		update: {},
		create : {
			achievement_id: 3,
			name: "Noob",
			description: "You have lost a game.",
			lose_requirement: 1
	}});

	await prisma.achievement.upsert({
		where: {
			achievement_id: 4,
		},
		update: {},
		create : {
			achievement_id: 4,
			name: "Beginer's luck",
			description: "You have won a game.",
			win_requirement: 1
	}});

	await prisma.achievement.upsert({
		where: {
			achievement_id: 5,
		},
		update: {},
		create : {
			achievement_id: 5,
			name: "World champion",
			description: "You have won 10 games.",
			win_requirement: 10
	}});

	await prisma.achievement.upsert({
		where: {
			achievement_id: 6,
		},
		update: {},
		create : {
			achievement_id: 6,
			name: "Get a life",
			description: "You have played 20 games.",
			play_requirement: 20
	}});

  // create three dummy users
    const user1 = await prisma.user.upsert({
      where: { username: 'Archi' },
      update: {},
      create: {
        username: 'Archi',
		exp: 534
      },
    });

    const user2 = await prisma.user.upsert({
      where: { username: 'Noam' },
      update: {},
      create: {
        username: 'Noam',
		exp:43
      },
    });

    const user3 = await prisma.user.upsert({
        where: { username: 'Meziane' },
        update: {},
        create: {
            username: 'Meziane',
			exp:174
        },
      });

// create two dummy canals
    const canal1 = await prisma.canal.upsert({
      where: { name: 'Générale' },
      update: {},
      create: {
        name: 'Générale',
        type: 'public',
        password: ''
      },
    });

    const canal2 = await prisma.canal.upsert({
      where: { name: 'Private chan' },
      update: {},
      create: {
        name: 'Private chan',
        type: 'protected',
        password: 'canalpass'
      },
    });

    const canal3 = await prisma.canal.upsert({
      where: { name: 'Random' },
      update: {},
      create: {
        name: 'Random',
        type: 'public',
        password: ''
      },
    });

    const canal4 = await prisma.canal.upsert({
      where: { name: 'Game' },
      update: {},
      create: {
        name: 'Game',
        type: 'public',
        password: ''
      },
    });



	//create dummy matches

	await prisma.match_history.create({ data: {
			loser_id: 1,
			loser_score: 5,
			winner_id: 2,
			winner_score: 11,
		},
	});

	await prisma.match_history.create({ data: {
			loser_id: 3,
			loser_score: 7,
			winner_id: 2,
			winner_score: 11,
		},
	});

	await prisma.match_history.create({ data: {
			loser_id: 2,
			loser_score: 7,
			winner_id: 1,
			winner_score: 11,
		},
	});

	await prisma.match_history.create({ data: {
			loser_id: 2,
			loser_score: 2,
			winner_id: 3,
			winner_score: 11,
		},
	});

	// //create dummy earned achievements. Doesn't check if it already exists so might have doubles

	await prisma.earned_achievement.create({
		data: {
			user_id: 1,
			achievement_id: 1
		},
	});

	await prisma.earned_achievement.create({
		data: {
			user_id: 1,
			achievement_id: 2
		},
	});

	await prisma.earned_achievement.create({
		data: {
			user_id: 1,
			achievement_id: 4
		},
	});

	await prisma.earned_achievement.create({
		data: {
			user_id: 1,
			achievement_id: 5
		},
	});

	await prisma.earned_achievement.create({
		data: {
			user_id: 2,
			achievement_id: 4
		},
	});

	await prisma.earned_achievement.create({
		data: {
			user_id: 2,
			achievement_id: 6
		},
	});


  console.log({ user1, user2, user3 });
  console.log({ canal1, canal2, canal3, canal4});

}

   
// execute the main function
main()
  .catch((e) => {
    console.error(e);
    process.exit(1);
  })
  .finally(async () => {
    // close Prisma Client at the end
    await prisma.$disconnect();
  });

