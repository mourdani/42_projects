import { SubscribeMessage, WebSocketGateway, WebSocketServer, OnGatewayConnection, OnGatewayDisconnect } from '@nestjs/websockets';
import { Server, Socket } from 'socket.io';
import { ConnectedSocket } from '@nestjs/websockets';

@WebSocketGateway()
export class SocketIoGateway implements OnGatewayConnection, OnGatewayDisconnect {
  @WebSocketServer()
  server: Server;

  handleConnection(@ConnectedSocket() client: any) {
    console.log('A zbrb has connected');
  }

  handleDisconnect(client: Socket) {
    console.log('A zbrb has disconnected');
  }

  @SubscribeMessage('sendMessage')
  handleMessage(client: Socket, messageData: any) {
    console.log('Received message:', messageData);
    
    // You can then broadcast the message to other connected clients
    client.broadcast.emit('newMessage', messageData);
  }

  @SubscribeMessage('create-room')
  createRoom(client: Socket) {
    console.log('Room created');
  }
}
